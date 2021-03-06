/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "i64toi64set_shared_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace OpenStars { namespace Core { namespace I64ToI64Set { namespace Data {


TValue::~TValue() throw() {
}


void TValue::__set_items(const std::vector<TItem> & val) {
  this->items = val;
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

  bool isset_items = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->items.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->items.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readI64(this->items[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          isset_items = true;
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

  if (!isset_items)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TValue::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TValue");

  xfer += oprot->writeFieldBegin("items", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->items.size()));
    std::vector<TItem> ::const_iterator _iter5;
    for (_iter5 = this->items.begin(); _iter5 != this->items.end(); ++_iter5)
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
  swap(a.items, b.items);
}

TValue::TValue(const TValue& other6) {
  items = other6.items;
}
TValue& TValue::operator=(const TValue& other7) {
  items = other7.items;
  return *this;
}
void TValue::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TValue(";
  out << "items=" << to_string(items);
  out << ")";
}

}}}} // namespace
