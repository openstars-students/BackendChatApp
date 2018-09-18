/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "contactstore_types.h"

namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::UserConversationService::TValue data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::UserConversationService::TValue& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::UserConversationService::TValue& value) {
            this->data = value;
        }
        OpenStars::Platform::UserConversationService::TErrorCode::type additem(const int64_t item) {
            OpenStars::Platform::UserConversationService::TErrorCode error;
            bool kt=true;
            for(std::vector<int64_t>::iterator pos = data.listcid.begin(); pos!=data.listcid.end(); pos++)
            {
                if(*pos==item)
                {
                    kt=false;
                }
                
            }
            if(kt)
            {
                data.listcid.push_back(item);
                return error.EGood;
            }
            else{
                return error.EDataExisted;
            }
            /*
            std::cout<<"gia tri pos "<<*pos<<std::endl;
            std::cout<<"vi tri END "<<int(data.listuid.end()-data.listuid.begin())<<std::endl;
            std::cout<<"vi tri pos "<<int(pos-data.listuid.begin())<<std::endl;
            if ((pos == data.listuid.end()) || (*pos != item)) {
                data.listuid.insert(pos, item);
                std::cout<<"vao den day!"<<std::endl;
                return error.EGood;
                
            }
            if(*pos==item) return error.EDataExisted;*/
            return error.EUnknown;
        }
        OpenStars::Platform::UserConversationService::TErrorCode::type removeitem(const int64_t item) {
            OpenStars::Platform::UserConversationService::TErrorCode error;
            std::vector<int64_t>::iterator pos = std::lower_bound(data.listcid.begin(), data.listcid.end(), item);
            //std::cout<<"\tgia tri"<<*pos<<std::endl;
            if ((pos != data.listcid.end()) && (*pos == item)) {
                data.listcid.erase(pos);
                //std::cout<<"vao den day! "<<std::endl;
                return error.EGood;            
            }
            if(*pos!=item) return error.ENotFound;
            return error.EUnknown;
        }

    };

}

#endif 
