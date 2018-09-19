/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "listmemberservice_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace OpenStars { namespace Platform { namespace ListMemberService {

int _kTErrorCodeValues[] = {
  TErrorCode::EGood,
  TErrorCode::ENotFound,
  TErrorCode::EUnknown,
  TErrorCode::EDataExisted
};
const char* _kTErrorCodeNames[] = {
  "EGood",
  "ENotFound",
  "EUnknown",
  "EDataExisted"
};
const std::map<int, const char*> _TErrorCode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kTErrorCodeValues, _kTErrorCodeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TErrorCode::type& val) {
  std::map<int, const char*>::const_iterator it = _TErrorCode_VALUES_TO_NAMES.find(val);
  if (it != _TErrorCode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


TValue::~TValue() throw() {
}


void TValue::__set_uid(const TKey val) {
  this->uid = val;
}

void TValue::__set_listuid(const std::vector<int64_t> & val) {
  this->listuid = val;
}
std::ostream& operator<<(std::ostream& out, const TValue& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TValue::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->uid);
          this->__isset.uid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->listuid.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->listuid.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readI64(this->listuid[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.listuid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TValue::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TValue");

  xfer += oprot->writeFieldBegin("uid", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->uid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("listuid", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->listuid.size()));
    std::vector<int64_t> ::const_iterator _iter5;
    for (_iter5 = this->listuid.begin(); _iter5 != this->listuid.end(); ++_iter5)
    {
      xfer += oprot->writeI64((*_iter5));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TValue &a, TValue &b) {
  using ::std::swap;
  swap(a.uid, b.uid);
  swap(a.listuid, b.listuid);
  swap(a.__isset, b.__isset);
}

TValue::TValue(const TValue& other6) {
  uid = other6.uid;
  listuid = other6.listuid;
  __isset = other6.__isset;
}
TValue& TValue::operator=(const TValue& other7) {
  uid = other7.uid;
  listuid = other7.listuid;
  __isset = other7.__isset;
  return *this;
}
void TValue::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TValue(";
  out << "uid=" << to_string(uid);
  out << ", " << "listuid=" << to_string(listuid);
  out << ")";
}


TDataResult::~TDataResult() throw() {
}


void TDataResult::__set_errorCode(const TErrorCode::type val) {
  this->errorCode = val;
}

void TDataResult::__set_data(const TValue& val) {
  this->data = val;
__isset.data = true;
}
std::ostream& operator<<(std::ostream& out, const TDataResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TDataResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast8;
          xfer += iprot->readI32(ecast8);
          this->errorCode = (TErrorCode::type)ecast8;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->data.read(iprot);
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TDataResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TDataResult");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.data) {
    xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->data.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TDataResult &a, TDataResult &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

TDataResult::TDataResult(const TDataResult& other9) {
  errorCode = other9.errorCode;
  data = other9.data;
  __isset = other9.__isset;
}
TDataResult& TDataResult::operator=(const TDataResult& other10) {
  errorCode = other10.errorCode;
  data = other10.data;
  __isset = other10.__isset;
  return *this;
}
void TDataResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDataResult(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "data="; (__isset.data ? (out << to_string(data)) : (out << "<null>"));
  out << ")";
}

}}} // namespace
