# 🛡️ Memory Sentinel: Polyglot Security Suite

**High-performance file encryption engine with a multi-language automated workflow.**

## Screenshot
<img width="1147" height="668" alt="sent2" src="https://github.com/user-attachments/assets/7492d6cf-c582-4239-971c-db757295bcce" />


## 🏗️ Polyglot Architecture
This project demonstrates how to integrate different technologies to build a robust security tool:

* **Core (C++):** Handles low-level bitwise XOR encryption and manual heap memory management for maximum performance.
* **Orchestrator (Python):** Automates the discovery of sensitive files and manages the execution flow.
* **Automation (Bash):** Handles environment setup, permissions, and secure cleanup of forensic traces.

## 🛠️ Technical Deep Dive
- **Memory Safety:** Manual `malloc`/`free` cycles with RAII principles in C++.
- **Integrity:** Checksum validation to ensure data hasn't been tampered with.
- **Interoperability:** Python `subprocess` integration to bridge high-level logic with native binaries.
- **Forensic Cleanup:** Automated removal of temporary cleartext files.

## 🚀 Quick Start
1. **Compile the Core:**
   `g++ -O3 -static -o sentinel main.cpp`

2. **Run the Orchestrator:**
   `python orchestrator.py`

3. **Secure Cleanup:**
   `./cleanup.sh`

---
**Developed by [Jorge Otero](https://github.com/Jorgeotero1998)** *Python Automation Engineer | Cybersecurity & SOC Analyst*
