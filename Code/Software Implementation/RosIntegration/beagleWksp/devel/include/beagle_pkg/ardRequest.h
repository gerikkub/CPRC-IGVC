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
 * Auto-generated by genmsg_cpp from file /home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/ard.srv
 *
 */


#ifndef BEAGLE_PKG_MESSAGE_ARDREQUEST_H
#define BEAGLE_PKG_MESSAGE_ARDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace beagle_pkg
{
template <class ContainerAllocator>
struct ardRequest_
{
  typedef ardRequest_<ContainerAllocator> Type;

  ardRequest_()
    : command(0)  {
    }
  ardRequest_(const ContainerAllocator& _alloc)
    : command(0)  {
    }



   typedef int64_t _command_type;
  _command_type command;




  typedef boost::shared_ptr< ::beagle_pkg::ardRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::beagle_pkg::ardRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct ardRequest_

typedef ::beagle_pkg::ardRequest_<std::allocator<void> > ardRequest;

typedef boost::shared_ptr< ::beagle_pkg::ardRequest > ardRequestPtr;
typedef boost::shared_ptr< ::beagle_pkg::ardRequest const> ardRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::beagle_pkg::ardRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::beagle_pkg::ardRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace beagle_pkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg'], 'beagle_pkg': ['/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::beagle_pkg::ardRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::beagle_pkg::ardRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beagle_pkg::ardRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beagle_pkg::ardRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beagle_pkg::ardRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beagle_pkg::ardRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::beagle_pkg::ardRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "856b30ed20a04e555abc88aa6a08af67";
  }

  static const char* value(const ::beagle_pkg::ardRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x856b30ed20a04e55ULL;
  static const uint64_t static_value2 = 0x5abc88aa6a08af67ULL;
};

template<class ContainerAllocator>
struct DataType< ::beagle_pkg::ardRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "beagle_pkg/ardRequest";
  }

  static const char* value(const ::beagle_pkg::ardRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::beagle_pkg::ardRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 command\n\
";
  }

  static const char* value(const ::beagle_pkg::ardRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::beagle_pkg::ardRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ardRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::beagle_pkg::ardRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::beagle_pkg::ardRequest_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    Printer<int64_t>::stream(s, indent + "  ", v.command);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEAGLE_PKG_MESSAGE_ARDREQUEST_H
