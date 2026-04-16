import os
import subprocess

def secure_vault():
    print("--- SENTINEL ORCHESTRATOR (Python + C++) ---")
    files = [f for f in os.listdir('.') if f.endswith('.txt')]
    
    for file in files:
        if not file.endswith('.enc'):
            print(f"[*] Protegiendo: {file}")
            # Python llama al binario de C++ que compilaste
            subprocess.run(['./sentinel', file])
            print(f"[+] {file} cifrado exitosamente.")

if __name__ == "__main__":
    secure_vault()
