#!/bin/bash
# Eugene Auduchinok, 2014

function notify_success() {
	printf "Build succeeded.\nSending email..\n"
	mutt -s "Build succeeded." -- $LOG_MAIL <<< "Yo. I've just finished building your project. It was OK."
}

function notify_fail() {
	echo "There was an error during build."
	echo "Sending email with log file.."
	mutt -a $1 -s "Build failed." -- $LOG_MAIL <<< "Build log is in the attachment."
}

function clone() {
	echo "Loading config.."
	source config.sh

	echo "Cleaning working folder.."
	rm -rf $REPO_NAME

	echo "Cloning project from remote repo.."
	if ! git clone $REPO_PATH &> clone_log.txt
	then
	    notify_fail clone_log.txt
	    exit 1
	fi
}

function build() {
	echo "Building workspace.."
	xbuild $SOLUTION_PATH &> build_log.txt

	while read file; do
		if [ ! -f $file ]
		then
			notify_fail build_log.txt
			exit 1
		fi
	done < expected_files.txt

	notify_success
}

clone
build