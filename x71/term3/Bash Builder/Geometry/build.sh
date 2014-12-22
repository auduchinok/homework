#!/bin/bash
# Eugene Auduchinok, 2014

echo "Loading config.."
source config.sh


echo "Cleaning working folder.."
rm -rf $REPO_NAME


echo "Cloning project from remote repo.."
git clone $REPO_PATH


echo "Building workspace.."
xbuild $SOLUTION_PATH &> build_log.txt
if find . -name "*.exe" | grep -q "bin"
then
	printf "Build succeeded.\nSending email..\n"
	mail -s "Build succeeded." $LOG_MAIL <<< "Yo. I've just finished building your project. It was OK."
else
	echo "There was an error during build."
	echo "Sending email with log file.."
	mutt -a build_log.txt -s "Build failed" -- $LOG_MAIL <<< "Build log is in the attachment."
fi

# I've used different ways to send email and to print text
# for better remembering of using these things.