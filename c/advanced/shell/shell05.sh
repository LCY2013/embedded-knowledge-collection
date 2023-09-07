#!/bin/bash

# The statement of case...esac
if [ $# -eq 0 ]
then
  echo "No argument is declared"
  exit
fi
case $1 in
  shell01.sh)
    echo "User selects shell01.sh"
    ;;
  shell02.sh)
      echo "User selects shell02.sh"
      ;;
  shell03.sh)
      echo "User selects shell03.sh"
      ;;
  *)
      echo "You must select either shell01.sh、shell02.sh、shell03.sh"
      ;;
esac