; Auto-generated. Do not edit!


(cl:in-package beagle_pkg-srv)


;//! \htmlinclude ard-request.msg.html

(cl:defclass <ard-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:integer
    :initform 0))
)

(cl:defclass ard-request (<ard-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ard-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ard-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beagle_pkg-srv:<ard-request> is deprecated: use beagle_pkg-srv:ard-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <ard-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beagle_pkg-srv:command-val is deprecated.  Use beagle_pkg-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ard-request>) ostream)
  "Serializes a message object of type '<ard-request>"
  (cl:let* ((signed (cl:slot-value msg 'command)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ard-request>) istream)
  "Deserializes a message object of type '<ard-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ard-request>)))
  "Returns string type for a service object of type '<ard-request>"
  "beagle_pkg/ardRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ard-request)))
  "Returns string type for a service object of type 'ard-request"
  "beagle_pkg/ardRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ard-request>)))
  "Returns md5sum for a message object of type '<ard-request>"
  "cbd6abbe8ea9a10f24753129c2f80da6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ard-request)))
  "Returns md5sum for a message object of type 'ard-request"
  "cbd6abbe8ea9a10f24753129c2f80da6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ard-request>)))
  "Returns full string definition for message of type '<ard-request>"
  (cl:format cl:nil "int64 command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ard-request)))
  "Returns full string definition for message of type 'ard-request"
  (cl:format cl:nil "int64 command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ard-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ard-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ard-request
    (cl:cons ':command (command msg))
))
;//! \htmlinclude ard-response.msg.html

(cl:defclass <ard-response> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass ard-response (<ard-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ard-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ard-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beagle_pkg-srv:<ard-response> is deprecated: use beagle_pkg-srv:ard-response instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <ard-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beagle_pkg-srv:distance-val is deprecated.  Use beagle_pkg-srv:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ard-response>) ostream)
  "Serializes a message object of type '<ard-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ard-response>) istream)
  "Deserializes a message object of type '<ard-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ard-response>)))
  "Returns string type for a service object of type '<ard-response>"
  "beagle_pkg/ardResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ard-response)))
  "Returns string type for a service object of type 'ard-response"
  "beagle_pkg/ardResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ard-response>)))
  "Returns md5sum for a message object of type '<ard-response>"
  "cbd6abbe8ea9a10f24753129c2f80da6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ard-response)))
  "Returns md5sum for a message object of type 'ard-response"
  "cbd6abbe8ea9a10f24753129c2f80da6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ard-response>)))
  "Returns full string definition for message of type '<ard-response>"
  (cl:format cl:nil "float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ard-response)))
  "Returns full string definition for message of type 'ard-response"
  (cl:format cl:nil "float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ard-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ard-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ard-response
    (cl:cons ':distance (distance msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ard)))
  'ard-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ard)))
  'ard-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ard)))
  "Returns string type for a service object of type '<ard>"
  "beagle_pkg/ard")