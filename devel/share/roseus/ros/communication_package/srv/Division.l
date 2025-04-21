;; Auto-generated. Do not edit!


(when (boundp 'communication_package::Division)
  (if (not (find-package "COMMUNICATION_PACKAGE"))
    (make-package "COMMUNICATION_PACKAGE"))
  (shadow 'Division (find-package "COMMUNICATION_PACKAGE")))
(unless (find-package "COMMUNICATION_PACKAGE::DIVISION")
  (make-package "COMMUNICATION_PACKAGE::DIVISION"))
(unless (find-package "COMMUNICATION_PACKAGE::DIVISIONREQUEST")
  (make-package "COMMUNICATION_PACKAGE::DIVISIONREQUEST"))
(unless (find-package "COMMUNICATION_PACKAGE::DIVISIONRESPONSE")
  (make-package "COMMUNICATION_PACKAGE::DIVISIONRESPONSE"))

(in-package "ROS")





(defclass communication_package::DivisionRequest
  :super ros::object
  :slots (_numerator _denominator ))

(defmethod communication_package::DivisionRequest
  (:init
   (&key
    ((:numerator __numerator) 0.0)
    ((:denominator __denominator) 0.0)
    )
   (send-super :init)
   (setq _numerator (float __numerator))
   (setq _denominator (float __denominator))
   self)
  (:numerator
   (&optional __numerator)
   (if __numerator (setq _numerator __numerator)) _numerator)
  (:denominator
   (&optional __denominator)
   (if __denominator (setq _denominator __denominator)) _denominator)
  (:serialization-length
   ()
   (+
    ;; float64 _numerator
    8
    ;; float64 _denominator
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _numerator
       (sys::poke _numerator (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _denominator
       (sys::poke _denominator (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _numerator
     (setq _numerator (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _denominator
     (setq _denominator (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass communication_package::DivisionResponse
  :super ros::object
  :slots (_result _success ))

(defmethod communication_package::DivisionResponse
  (:init
   (&key
    ((:result __result) 0.0)
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _result (float __result))
   (setq _success __success)
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; float64 _result
    8
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _result
       (sys::poke _result (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _result
     (setq _result (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass communication_package::Division
  :super ros::object
  :slots ())

(setf (get communication_package::Division :md5sum-) "40e9c5898eacc0da947d7d8e72bf20eb")
(setf (get communication_package::Division :datatype-) "communication_package/Division")
(setf (get communication_package::Division :request) communication_package::DivisionRequest)
(setf (get communication_package::Division :response) communication_package::DivisionResponse)

(defmethod communication_package::DivisionRequest
  (:response () (instance communication_package::DivisionResponse :init)))

(setf (get communication_package::DivisionRequest :md5sum-) "40e9c5898eacc0da947d7d8e72bf20eb")
(setf (get communication_package::DivisionRequest :datatype-) "communication_package/DivisionRequest")
(setf (get communication_package::DivisionRequest :definition-)
      "float64 numerator
float64 denominator
---
float64 result
bool success
")

(setf (get communication_package::DivisionResponse :md5sum-) "40e9c5898eacc0da947d7d8e72bf20eb")
(setf (get communication_package::DivisionResponse :datatype-) "communication_package/DivisionResponse")
(setf (get communication_package::DivisionResponse :definition-)
      "float64 numerator
float64 denominator
---
float64 result
bool success
")



(provide :communication_package/Division "40e9c5898eacc0da947d7d8e72bf20eb")


