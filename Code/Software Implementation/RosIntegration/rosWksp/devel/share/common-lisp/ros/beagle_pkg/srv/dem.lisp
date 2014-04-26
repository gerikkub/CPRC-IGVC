; Auto-generated. Do not edit!


(cl:in-package beagle_pkg-srv)


;//! \htmlinclude dem-request.msg.html

(cl:defclass <dem-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:integer
    :initform 0))
)

(cl:defclass dem-request (<dem-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <dem-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'dem-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beagle_pkg-srv:<dem-request> is deprecated: use beagle_pkg-srv:dem-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <dem-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beagle_pkg-srv:command-val is deprecated.  Use beagle_pkg-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <dem-request>) ostream)
  "Serializes a message object of type '<dem-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <dem-request>) istream)
  "Deserializes a message object of type '<dem-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<dem-request>)))
  "Returns string type for a service object of type '<dem-request>"
  "beagle_pkg/demRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'dem-request)))
  "Returns string type for a service object of type 'dem-request"
  "beagle_pkg/demRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<dem-request>)))
  "Returns md5sum for a message object of type '<dem-request>"
  "7e99c275c708f2a944f8a662652face0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'dem-request)))
  "Returns md5sum for a message object of type 'dem-request"
  "7e99c275c708f2a944f8a662652face0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<dem-request>)))
  "Returns full string definition for message of type '<dem-request>"
  (cl:format cl:nil "int64 command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'dem-request)))
  "Returns full string definition for message of type 'dem-request"
  (cl:format cl:nil "int64 command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <dem-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <dem-request>))
  "Converts a ROS message object to a list"
  (cl:list 'dem-request
    (cl:cons ':command (command msg))
))
;//! \htmlinclude dem-response.msg.html

(cl:defclass <dem-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:integer
    :initform 0))
)

(cl:defclass dem-response (<dem-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <dem-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'dem-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beagle_pkg-srv:<dem-response> is deprecated: use beagle_pkg-srv:dem-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <dem-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beagle_pkg-srv:result-val is deprecated.  Use beagle_pkg-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <dem-response>) ostream)
  "Serializes a message object of type '<dem-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <dem-response>) istream)
  "Deserializes a message object of type '<dem-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<dem-response>)))
  "Returns string type for a service object of type '<dem-response>"
  "beagle_pkg/demResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'dem-response)))
  "Returns string type for a service object of type 'dem-response"
  "beagle_pkg/demResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<dem-response>)))
  "Returns md5sum for a message object of type '<dem-response>"
  "7e99c275c708f2a944f8a662652face0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'dem-response)))
  "Returns md5sum for a message object of type 'dem-response"
  "7e99c275c708f2a944f8a662652face0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<dem-response>)))
  "Returns full string definition for message of type '<dem-response>"
  (cl:format cl:nil "int64 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'dem-response)))
  "Returns full string definition for message of type 'dem-response"
  (cl:format cl:nil "int64 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <dem-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <dem-response>))
  "Converts a ROS message object to a list"
  (cl:list 'dem-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'dem)))
  'dem-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'dem)))
  'dem-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'dem)))
  "Returns string type for a service object of type '<dem>"
  "beagle_pkg/dem")