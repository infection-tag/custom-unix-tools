if [ -n "$ZSH_VERSION" ]; then
	# user is using zsh
	echo "alias meta="sh meta.sh"" >> ~/.zshrc
	echo "alias new-git="sh new-git.sh"" >> ~/.zshrc

elif [ -n "$BASH_VERSION" ]; then
	# user is using bash
	echo "alias meta="sh meta.sh"" >> ~/.bashrc
	echo "alias new-git="sh new-git.sh"" >> ~/.bashrc

fi
