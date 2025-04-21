
(cl:in-package :asdf)

(defsystem "communication_package-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Division" :depends-on ("_package_Division"))
    (:file "_package_Division" :depends-on ("_package"))
  ))