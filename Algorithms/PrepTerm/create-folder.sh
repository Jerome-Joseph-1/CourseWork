folderName="$@"

renamedFolder=$(echo "$folderName" | sed -e 's/\.//g' -e 's/ /-/g')

if [ -d $renamedFolder ]
then
echo "Error: Folder already exists!"
else
mkdir "$renamedFolder"
cp .template/template.cpp "$renamedFolder/main.cpp"
cp .template/run.sh "$renamedFolder"
touch "$renamedFolder/input.txt"
echo "1" | cat > "$renamedFolder/input.txt"
fi