;*========================================================================
;* VDIFAST Public Domain VDI bindings.
;*========================================================================

	.include	"vdimacro.s"

;*------------------------------------------------------------------------
;* Filled rectangle.
;*------------------------------------------------------------------------

_vr_recfl::
	.cargs	#4,.handle.w,.pxy.l
	moveq.l	#114,d0
	moveq.l	#0,d1
	moveq.l	#2,d2
	move.l	.pxy(sp),a0
	jmp	vout_pxy

	end
