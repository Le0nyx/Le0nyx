#!/bin/bash

echo "Parameter needs to be: <source folder> <target folder> <YYYY-MM-DD>"
# Überprüfe die Anzahl der übergebenen Parameter
if [ $# -ne 3 ]; then
    echo "Falsche Anzahl von Parametern. Verwende: $0 <Quellordner> <Zielordner> <Datum>"
    exit 1
fi

# Überprüfe, ob der Quellordner existiert
if [ ! -d "$1" ]; then
    echo "Quellordner existiert nicht: $1"
    exit 1
fi

# Überprüfe, ob der Zielordner existiert oder erstelle ihn
if [ ! -d "$2" ]; then
    mkdir -p "$2"
    if [ $? -ne 0 ]; then
        echo "Fehler beim Erstellen des Zielordners: $2"
        exit 1
    fi
fi

# Überprüfe das angegebene Datum im Format YYYY-MM-DD
date -d "$3" >/dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Ungültiges Datum: $3"
    exit 1
fi

# Rekursive Funktion zum Durchlaufen des Quellordners
function process_files {
    local source_dir="$1"
    local target_dir="$2"
    local date="$3"

    for file in "$source_dir"/*; do
        if [ -f "$file" ]; then
            # Überprüfe, ob die Datei nach dem angegebenen Datum geändert wurde
            if [ "$file" -nt "$date" ]; then
                # Erstelle die Zielordnerstruktur
                local relative_path="${file#$source_dir}"
                local target_file="$target_dir$relative_path"
                mkdir -p "$(dirname "$target_file")"

                # Kopiere die Datei in den Zielordner
                cp "$file" "$target_file"
                if [ $? -ne 0 ]; then
                    echo "Fehler beim Kopieren der Datei: $file"
                fi
            fi
        elif [ -d "$file" ]; then
            # Rufe die Funktion rekursiv für Unterordner auf
            process_files "$file" "$target_dir" "$date"
        fi
    done
}

# Rufe die Funktion mit den übergebenen Parametern auf
process_files "$1" "$2" "$3"