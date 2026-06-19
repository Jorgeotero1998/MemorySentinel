# MemorySentinel 🛡️
> High-Performance Native C++17 Security Engine & Polyglot Automation Suite.

MemorySentinel is a low-level security and file-protection engine built in native C++17, designed to execute high-performance bitwise cryptographic operations directly in system memory. It operates within a polyglot architecture (C++, Python, and Bash) to deliver an automated, decoupled, and evasion-resilient workflow for sensitive data handling.

---

## 🏗️ Polyglot Architecture & Design

The suite leverages the unique strengths of different programming paradigms to achieve maximum performance and operational security:

*   **Core Engine (C++17):** Handles native file-system I/O, bitwise XOR cryptographic operations, and deterministic memory allocation. Engineered without external DLL dependencies to maintain a minimal footprint and prevent common injection vectors.
*   **Orchestration Layer (Python):** Automates target discovery, processes asynchronous file structures, and safely interfaces with the native binary via low-overhead subprocess pipes.
*   **Automation & Anti-Forensics (Bash):** Manages local execution permissions, controls secure environment configuration, and handles the absolute sanitization of forensic traces post-execution.

---

## 🚀 Key Technical Features

*   **Zero-DLL Dependency (AV/EDR Evasion):** Logic migrated fully into native C++17 code, compiling into a static, standalone binary that mitigates DLL blocking and API hooking mechanics.
*   **Deterministic Memory Control:** Implements manual memory management paired with RAII (Resource Acquisition Is Initialization) design patterns to eliminate memory leaks, pointer corruption, and heap overhead.
*   **Cryptographic Integrity Validation:** Integrates runtime checksum verifications to ensure that data blocks remain untampered with during the processing lifecycle.
*   **Automated Forensic Cleanup:** The automated teardown script handles the secure shredding of cleartext caches and temporary system artifacts to prevent post-incident forensic recovery.

---

## Screenshot
<img width="1147" height="668" alt="sent2" src="https://github.com/user-attachments/assets/7492d6cf-c582-4239-971c-db757295bcce" />



## 📁 Project Structure

```text
MemorySentinel/
├── main.cpp         # Native C++17 cryptographic and memory core logic
├── cleanup.sh       # Bash automation script for forensic trace sanitization
├── .gitignore       # Pre-configured rules to exclude local binaries and build objects
└── README.md        # Technical documentation
