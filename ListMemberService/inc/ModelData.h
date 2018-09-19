/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "listmemberservice_types.h"
#include <iostream>
#include <algorithm>


namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::ListMemberService::TValue data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::ListMemberService::TValue& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::ListMemberService::TValue& value) {
            this->data = value;
        }
        OpenStars::Platform::ListMemberService::TErrorCode::type additem(const int64_t item) {
            OpenStars::Platform::ListMemberService::TErrorCode error;
            bool kt=true;
            for(std::vector<int64_t>::iterator pos = data.listuid.begin(); pos!=data.listuid.end(); pos++)
            {
                if(*pos==item)
                {
                    kt=false;
                }
                
            }
            if(kt)
            {
                data.listuid.push_back(item);
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
        
        OpenStars::Platform::ListMemberService::TErrorCode::type removeitem(const int64_t item) {
            OpenStars::Platform::ListMemberService::TErrorCode error;

            std::vector<int64_t>::iterator pos = std::find(data.listuid.begin(), data.listuid.end(), item);
            //std::cout<<"\tgia tri "<<*pos<<" input: "<<item<<std::endl;
            if ((pos != data.listuid.end()) && (*pos == item)) {
                data.listuid.erase(pos);
                //std::cout<<"vao den day! "<<std::endl;
                return error.EGood;            
            }
            if(*pos!=item) return error.ENotFound;
            return error.EUnknown;
        }

    };
    

}

#endif 
