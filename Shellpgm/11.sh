summarize_dir() {
    dir="$1"
    file_ext=""
    count=0
    num_files=$(find "$dir" -type f | wc -l)
    echo "Total Number of Files in the Directory: $num_files"
    for file in $(find "$dir" -type f); do
        file_ext=$(echo "${file##*.}")
        echo "$file_ext"
    done | sort -u > extensions.txt
    while read ext; do
        count=$(find "$dir" -type f -name "*.$ext" | wc -l)
        echo "$ext: $count"
    done < extensions.txt
    rm extensions.txt
}
if [ -z "$1" ]; then
    echo "Usage: summarize_directory [directory]"
    exit 1
fi
if [ ! -d "$1" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi
for subdir in $(find "$1" -type d); do
    summarize_dir "$subdir"
done

