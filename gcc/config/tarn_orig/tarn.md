;; -------------------------------------------------------------------------
;; Move instructions
;; -------------------------------------------------------------------------

;; SImode

;; (define_insn "movqi"
;;   [(set (match_operand:QI 0 "general_operand" "")
;; 	(match_operand:QI 1 "general_operand" ""))]
;;   ""
;;   "mov %0 %1 ,0")

;; -------------------------------------------------------------------------
;; Jump instructions
;; -------------------------------------------------------------------------

;; (define_insn "indirect_jump"
;;   [(set (pc) (match_operand:QI 0 "nonimmediate_operand" ""))]
;;   ""
;;   "jmp %0")

;; (define_insn "jump"
;;   [(set (pc)
;; 	(label_ref (match_operand 0 "" "")))]
;;   ""
;;   "jmp %l0%#")

;; (define_insn "nop"
;;   [(const_int 0)]
;;   ""
;;   "nop%."
;;   [(set_attr "type" "nop")])


;; -------------------------------------------------------------------------
;; Move instructions
;; -------------------------------------------------------------------------

;; SImode

(define_insn "movsi"
  [(set (match_operand:SI 0 "general_operand" "")
	(match_operand:SI 1 "general_operand" ""))]
  ""
  "mov %0, %1")

;; -------------------------------------------------------------------------
;; Jump instructions
;; -------------------------------------------------------------------------

(define_insn "indirect_jump"
  [(set (pc) (match_operand:SI 0 "nonimmediate_operand" "r"))]
  ""
  "jmp %0")

(define_insn "jump"
  [(set (pc)
	(label_ref (match_operand 0 "" "")))]
  ""
  "jmp %l0%#")