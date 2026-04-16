#!/bin/bash
echo "--- SYSTEM CLEANUP (Bash) ---"
rm -v secreto.txt prueba.txt 2>/dev/null
echo "[!] Archivos temporales eliminados."
ls -l
