/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include <iostream>
#include "listmessageservice_types.h"
#include <algorithm>
namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::ListMessageService::TValue data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::ListMessageService::TValue& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::ListMessageService::TValue& value) {
            this->data = value;
        }
        OpenStars::Platform::ListMessageService::TErrorCode::type additem(const int64_t item) {
            OpenStars::Platform::ListMessageService::TErrorCode error;
            bool kt=true;
            for(std::vector<int64_t>::iterator pos = data.listmid.begin(); pos!=data.listmid.end(); pos++)
            {
                if(*pos==item)
                {
                    kt=false;
                }
                
            }
            if(kt)
            {
                data.listmid.push_back(item);
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
        OpenStars::Platform::ListMessageService::TErrorCode::type removeitem(const int64_t item) {
            OpenStars::Platform::ListMessageService::TErrorCode error;
            std::vector<int64_t>::iterator pos = std::find(data.listmid.begin(), data.listmid.end(), item);
            //std::cout<<"\tgia tri "<<*pos<<" input: "<<item<<std::endl;
            if ((pos != data.listmid.end()) && (*pos == item)) {
                data.listmid.erase(pos);
               // std::cout<<"vao den day! "<<std::endl;
                return error.EGood;            
            }
            if(pos==data.listmid.end()) return error.ENotFound;
            return error.EUnknown;
        }

    };

}

#endif 
