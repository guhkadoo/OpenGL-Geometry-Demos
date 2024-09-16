if [ -z "$1" ]; then
    exit 1
fi

filename="$1"
g++ "$filename" -lGL -lGLU -lglut

if [ $? -eq 0 ]; then
    echo "Compilation successful";
else
    echo "Compilation failed";
fi
