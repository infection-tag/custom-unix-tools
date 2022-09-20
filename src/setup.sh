mkdir ~/.custom # move all this stuff to .custom folder
cp -R . ~/.custom # move all source files to .custom

if [ -n "$ZSH_VERSION" ]; then
	# user is using zsh
	echo "alias meta="sh ~/.custom/meta.sh"" >> ~/.zshrc
	echo "alias new-git="sh ~/.custom/new-git.sh"" >> ~/.zshrc
	echo export $MANPATH="$MANPATH:/usr/local/man" >> ~/.zshrc

elif [ -n "$BASH_VERSION" ]; then
	# user is using bash
	echo "alias meta="sh meta.sh"" >> ~/.bashrc
	echo "alias new-git="sh new-git.sh"" >> ~/.bashrc
	echo export $MANPATH="$MANPATH:/usr/local/custom-man-pages" >> ~/.bashrc

fi;

# make a directory for custom-man-pages
cp -R ../custom-man-pages /usr/local/
