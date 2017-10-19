if [ "$CPLUS_INCLUDE_PATH" ]
then
  export CPLUS_INCLUDE_PATH="$(dirname $(readlink -f -e "${BASH_SOURCE[0]}"))/cxx-prettyprint:$CPLUS_INCLUDE_PATH"
else
  export CPLUS_INCLUDE_PATH="$(dirname $(readlink -f -e "${BASH_SOURCE[0]}"))/cxx-prettyprint"
fi

