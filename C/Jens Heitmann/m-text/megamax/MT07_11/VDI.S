					IMPORT  _VdiParB

					EXPORT	vdi_exec
					
vdi_exec:
					MOVEM.L  D0-D2/A0-A2,-(SP)
					MOVE		 #0x73,D0
					MOVE.L	 #_VdiParB,D1
					TRAP		 #2
					MOVEM.L	 (SP)+,D0-D2/A0-A2
					RTS
