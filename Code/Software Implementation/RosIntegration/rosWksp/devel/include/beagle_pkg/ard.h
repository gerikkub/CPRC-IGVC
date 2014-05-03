/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by gensrv_cpp from file /home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg/srv/ard.srv
 *
 */


#ifndef BEAGLE_PKG_MESSAGE_ARD_H
#define BEAGLE_PKG_MESSAGE_ARD_H

#include <ros/service_traits.h>


#include <beagle_pkg/ardRequest.h>
#include <beagle_pkg/ardResponse.h>


namespace beagle_pkg
{

struct ard
{

typedef ardRequest Request;
typedef ardResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ard
} // namespace beagle_pkg


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::beagle_pkg::ard > {
  static const char* value()
  {
    return "cbd6abbe8ea9a10f24753129c2f80da6";
  }

  static const char* value(const ::beagle_pkg::ard&) { return value(); }
};

template<>
struct DataType< ::beagle_pkg::ard > {
  static const char* value()
  {
    return "beagle_pkg/ard";
  }

  static const char* value(const ::beagle_pkg::ard&) { return value(); }
};


// service_traits::MD5Sum< ::beagle_pkg::ardRequest> should match 
// service_traits::MD5Sum< ::beagle_pkg::ard > 
template<>
struct MD5Sum< ::beagle_pkg::ardRequest>
{
  static const char* value()
  {
    return MD5Sum< ::beagle_pkg::ard >::value();
  }
  static const char* value(const ::beagle_pkg::ardRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::beagle_pkg::ardRequest> should match 
// service_traits::DataType< ::beagle_pkg::ard > 
template<>
struct DataType< ::beagle_pkg::ardRequest>
{
  static const char* value()
  {
    return DataType< ::beagle_pkg::ard >::value();
  }
  static const char* value(const ::beagle_pkg::ardRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::beagle_pkg::ardResponse> should match 
// service_traits::MD5Sum< ::beagle_pkg::ard > 
template<>
struct MD5Sum< ::beagle_pkg::ardResponse>
{
  static const char* value()
  {
    return MD5Sum< ::beagle_pkg::ard >::value();
  }
  static const char* value(const ::beagle_pkg::ardResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::beagle_pkg::ardResponse> should match 
// service_traits::DataType< ::beagle_pkg::ard > 
template<>
struct DataType< ::beagle_pkg::ardResponse>
{
  static const char* value()
  {
    return DataType< ::beagle_pkg::ard >::value();
  }
  static const char* value(const ::beagle_pkg::ardResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // BEAGLE_PKG_MESSAGE_ARD_H
