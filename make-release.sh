#!/bin/bash

EXCLUDES="--exclude=.* --exclude=cmake-build*"
RELEASE="Slang-Extensions_`svnversion`.tar.gz"

echo "Packing files for release ${RELEASE} ..."

tar cfvz ${RELEASE} ${EXCLUDES} *

echo ""
echo "Uploading files..."

scp ${RELEASE} madelmann@frs.sourceforge.net:/home/frs/project/objectivescript-extensions/

echo ""
echo "Cleanup..."

rm ${RELEASE}

echo ""
echo "done."

