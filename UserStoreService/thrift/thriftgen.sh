rm gen-cpp/*
../../../contribs/ApacheThrift/bin/thrift -r -gen cpp userstore.thrift
../../../contribs/ApacheThrift/bin/thrift -r -gen go  userstore.thrift
rm gen-cpp/*skele*
