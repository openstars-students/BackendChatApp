/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;


#if !SILVERLIGHT
[Serializable]
#endif
public partial class TValue : TBase
{

  public List<long> Items { get; set; }

  public TValue() {
  }

  public TValue(List<long> items) : this() {
    this.Items = items;
  }

  public void Read (TProtocol iprot)
  {
    bool isset_items = false;
    TField field;
    iprot.ReadStructBegin();
    while (true)
    {
      field = iprot.ReadFieldBegin();
      if (field.Type == TType.Stop) { 
        break;
      }
      switch (field.ID)
      {
        case 1:
          if (field.Type == TType.List) {
            {
              Items = new List<long>();
              TList _list0 = iprot.ReadListBegin();
              for( int _i1 = 0; _i1 < _list0.Count; ++_i1)
              {
                long _elem2 = 0;
                _elem2 = iprot.ReadI64();
                Items.Add(_elem2);
              }
              iprot.ReadListEnd();
            }
            isset_items = true;
          } else { 
            TProtocolUtil.Skip(iprot, field.Type);
          }
          break;
        default: 
          TProtocolUtil.Skip(iprot, field.Type);
          break;
      }
      iprot.ReadFieldEnd();
    }
    iprot.ReadStructEnd();
    if (!isset_items)
      throw new TProtocolException(TProtocolException.INVALID_DATA);
  }

  public void Write(TProtocol oprot) {
    TStruct struc = new TStruct("TValue");
    oprot.WriteStructBegin(struc);
    TField field = new TField();
    field.Name = "items";
    field.Type = TType.List;
    field.ID = 1;
    oprot.WriteFieldBegin(field);
    {
      oprot.WriteListBegin(new TList(TType.I64, Items.Count));
      foreach (long _iter3 in Items)
      {
        oprot.WriteI64(_iter3);
      }
      oprot.WriteListEnd();
    }
    oprot.WriteFieldEnd();
    oprot.WriteFieldStop();
    oprot.WriteStructEnd();
  }

  public override string ToString() {
    StringBuilder sb = new StringBuilder("TValue(");
    sb.Append("Items: ");
    sb.Append(Items);
    sb.Append(")");
    return sb.ToString();
  }

}

