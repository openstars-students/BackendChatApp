/* 
 * File:   ServiceHandler.h
 * Author: trungthanh
 *
 * Created on February 23, 2012, 6:40 PM
 */

#ifndef SERVICEHANDLER_H
#define SERVICEHANDLER_H

#include "ServiceModel.h"
#include "ServiceThriftHandlerBaseT.h"
#include "TI64ToI64SetService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
OpenStars::Core::I64ToI64Set::TI64ToI64SetServiceIf, OpenStars::Core::I64ToI64Set::TI64ToI64SetServiceProcessor > {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
    OpenStars::Core::I64ToI64Set::TI64ToI64SetServiceIf, OpenStars::Core::I64ToI64Set::TI64ToI64SetServiceProcessor > _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:

    virtual void getValue(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key) {
        if (m_pmodel)
            m_pmodel->getValue(_return, key);
    }

    virtual void getValue_random(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key, const int32_t size) {
        if (m_pmodel)
            m_pmodel->getValue_random(_return, key, size);
    }

    virtual void getValue_slice(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key, const int32_t idxFrom, const int32_t size) {
        if (m_pmodel)
            m_pmodel->getValue_slice(_return, key, idxFrom, size);
    }

    virtual void getValueMulti(std::map<OpenStars::Core::I64ToI64Set::Data::TKey, OpenStars::Core::I64ToI64Set::Data::TValue>& _return, const std::vector<OpenStars::Core::I64ToI64Set::Data::TKey>& keys) {
        if (m_pmodel)
            m_pmodel->getValueMulti(_return, keys);
    }

    virtual bool hasItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item) {
        if (m_pmodel)
            return m_pmodel->hasItem(key, item);
        return false;
    }

    virtual int32_t getSize(const OpenStars::Core::I64ToI64Set::Data::TKey key) {
        if (m_pmodel)
            return m_pmodel->getSize(key);
        return -1;
    }

    virtual void getSizeMulti(std::map<OpenStars::Core::I64ToI64Set::Data::TKey, int32_t>& _return, const std::vector<OpenStars::Core::I64ToI64Set::Data::TKey>& keys) {
        if (m_pmodel)
            m_pmodel->getSizeMulti(_return, keys);
    }

    virtual bool setItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {
        if (m_pmodel)
            return m_pmodel->setItems(key, items);
        return false;
    }

    virtual bool clearItems(const OpenStars::Core::I64ToI64Set::Data::TKey key) {
        if (m_pmodel)
            return m_pmodel->clearItems(key);
        return false;
    }

    virtual bool addItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item) {
        if (m_pmodel)
            return m_pmodel->addItem(key, item);
        return false;
    }

    virtual bool addItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {
        if (m_pmodel)
            return m_pmodel->addItems(key, items);
        return false;
    }

    virtual bool removeItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item) {
        if (m_pmodel)
            return m_pmodel->removeItem(key, item);
        return false;
    }

    virtual bool removeItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {
        if (m_pmodel)
            return m_pmodel->removeItems(key, items);
        return false;
    }
};

#endif /* SERVICEHANDLER_H */
