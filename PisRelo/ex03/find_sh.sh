find . -type f -name "*.sh" | rev | cut -d "." -f2 | cut -d "/" -f1 | rev
