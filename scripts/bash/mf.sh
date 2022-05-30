#!/bin/bash
FILE="$1"
basename="$(basename "$1")"

cppheader="$(echo "${basename}" | tr '[:lower:]' '[:upper:]' | tr '-' '_')"
namespace="$(echo "${basename}" | tr '-' '_')"


echo "#ifndef ${cppheader}_H
#define ${cppheader}_H

namespace ${namespace} {

} // namespace ${namespace}

#endif // ${cppheader}_H " > "./src/${FILE}.h"

echo "#include \"${FILE}.h\"

namespace ${namespace} {

} // namespace ${namespace}" > "./src/${FILE}.cc"

echo "#include \"${FILE}.h\"
#include \"gtest/gtest.h\"
" > "./test/${FILE}-test.cc"

echo "Created ./src/${FILE}.h ./src/${FILE}.cc and ./test/${FILE}-test.cc"