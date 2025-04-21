;; Auto-generated. Do not edit!


(when (boundp 'communication_package::Person)
  (if (not (find-package "COMMUNICATION_PACKAGE"))
    (make-package "COMMUNICATION_PACKAGE"))
  (shadow 'Person (find-package "COMMUNICATION_PACKAGE")))
(unless (find-package "COMMUNICATION_PACKAGE::PERSON")
  (make-package "COMMUNICATION_PACKAGE::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(defclass communication_package::Person
  :super ros::object
  :slots (_name _age _gender ))

(defmethod communication_package::Person
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:gender __gender) nil)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _gender __gender)
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:gender
   (&optional (__gender :null))
   (if (not (eq __gender :null)) (setq _gender __gender)) _gender)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _age
    1
    ;; bool _gender
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _age
       (write-byte _age s)
     ;; bool _gender
       (if _gender (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _gender
     (setq _gender (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get communication_package::Person :md5sum-) "514351469df485dedb4099f5454028df")
(setf (get communication_package::Person :datatype-) "communication_package/Person")
(setf (get communication_package::Person :definition-)
      "string name
uint8 age
bool gender
")



(provide :communication_package/Person "514351469df485dedb4099f5454028df")


