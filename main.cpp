#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <chrono>
#include <iomanip>

namespace fs = std::filesystem;

// Función para obtener timestamp profesional
std::string get_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%dT%H:%M:%S");
    return ss.str();
}

// Generador de Logs JSON nativo
void log_audit(std::string action, std::string target, std::string status) {
    std::ofstream log_file("sentinel_audit.log", std::ios::app);
    log_file << "{\"timestamp\": \"" << get_timestamp() 
             << "\", \"action\": \"" << action 
             << "\", \"target\": \"" << target 
             << "\", \"status\": \"" << status 
             << "\", \"operator\": \"Jorgeotero1998\"}" << std::endl;
}

int main() {
    // 1. Verificación de Seguridad (Token de Entorno)
    const char* env_token = getenv("SENTINEL_TOKEN");
    if (!env_token || std::strcmp(env_token, "SECRET_123") != 0) {
        std::cerr << " [!] UNAUTHORIZED: Security token missing or invalid." << std::endl;
        return 1;
    }

    std::cout << "--- 🛡️ MEMORY SENTINEL NATIVE MODE ---" << std::endl;

    // 2. Escaneo de archivos nativo (C++17)
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == ".txt" && entry.path().filename() != "sentinel_audit.log") {
            std::string filename = entry.path().string();
            std::cout << "[*] Shielding: " << filename << "... ";

            std::ifstream file(filename, std::ios::binary);
            if (!file) {
                log_audit("ENCRYPTION", filename, "FAILED_OPEN");
                std::cout << "ERROR" << std::endl;
                continue;
            }

            std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            // Cifrado Bitwise XOR
            for (char &c : buffer) c ^= 0xFF;

            std::ofstream outfile(filename + ".sentinel", std::ios::binary);
            outfile.write(buffer.data(), buffer.size());
            outfile.close();

            log_audit("ENCRYPTION", filename, "SUCCESS");
            std::cout << "DONE" << std::endl;
        }
    }
    return 0;
}
