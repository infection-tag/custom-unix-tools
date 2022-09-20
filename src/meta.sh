echo /------------------------------------------------------------------
du -sh 
pwd


# check if directory is git initalized
[ -d .git ] && echo Git initalized || git rev-parse --git-dir > /dev/null 2>&1

echo ------------------------------------------------------------------/
