#!/bin/bash
# Eugene Auduchinok, 2014

echo "Loading config.."
source config.sh


echo "Cleaning working folder.."
rm -rf $REPO_NAME


echo "Cloning project from remote repo.."
git clone $REPO_PATH


echo "Building workspace.."
xcodebuild -workspace $WORKSPACE_PATH -scheme icreated -sdk iphonesimulator &> build_log.txt

if grep -q "BUILD SUCCEEDED" build_log.txt
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