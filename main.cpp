#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

class Sentinel {
private:
    char* data;
    size_t size;
    const char* key;

    unsigned int calculate_checksum(char* b, size_t s) {
        unsigned int checksum = 0;
        for (size_t i = 0; i < s; i++) checksum += (unsigned char)b[i];
        return checksum;
    }

public:
    Sentinel(const char* encryption_key) : data(nullptr), size(0), key(encryption_key) {}

    bool process_file(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file.is_open()) return false;

        size = file.tellg();
        file.seekg(0, std::ios::beg);

        data = (char*)malloc(size);
        if (!data) return false;

        file.read(data, size);
        file.close();

        unsigned int checksum_before = calculate_checksum(data, size);
        
        size_t key_len = strlen(key);
        for (size_t i = 0; i < size; i++) data[i] ^= key[i % key_len];

        std::string out_name = filename + ".sentinel";
        std::ofstream out(out_name, std::ios::binary);
        if (out.is_open()) {
            out.write(data, size);
            out.close();
            std::cout << "Success. Checksum: " << std::hex << checksum_before << std::endl;
        }

        return true;
    }

    ~Sentinel() {
        if (data) free(data);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./sentinel <file>" << std::endl;
        return 1;
    }
    Sentinel engine("Industrial_Grade_Key_2026");
    if (!engine.process_file(argv[1])) {
        std::cerr << "Error processing file." << std::endl;
        return 1;
    }
    return 0;
}
