rm gen-cpp/*
../../../contribs/ApacheThrift/bin/thrift -r -gen cpp contactstore.thrift
../../../contribs/ApacheThrift/bin/thrift -r -gen go  contactstore.thrift
rm gen-cpp/*skele*
