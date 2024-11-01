dosseg
.model small
.stack 100h
.data
    arrM db "Array : $"
    arr  db 7,8,4,1,2
.code
main proc
                mov  ax ,@data
                mov  ds , ax
                call displayArr
                mov  bx , 4
    ;outer loop counter
                mov  cx , 4
    ;sorting using the bubble sort method

    outerLoop:  
    ;we need to reset the si pointer to first location in each iteration of the outer loop
                lea  si , arr

                push cx
    ;inner loop counter
                mov  cx , bx
    innerLoop:  
    ;we compare adjacent elements sequentially
                mov  al , [si]
                mov  dl , [si+1]
                cmp  al , dl
    ;if less then dont swap else swap
                jl   next
                mov  [si] , dl
                mov  [si+1] ,al
    next:       
                inc  si
                loop innerLoop
                pop  cx
                dec  bx

                loop outerLoop


                call displayArr
                mov  ah , 4ch
                int  21h
    ;making a display array procedure

displayArr proc
    ;displaying the Array Message
                lea  dx , arrM
                mov  ah , 9
                int  21h
    ;si points to the first element of the array
                lea  si , arr
                mov  cx , 5
    displayLoop:
                mov  dl ,[si]
    ;ASCII Adjustment
                add  dl , 48
                mov  ah , 2
                int  21h
    ;need to increment si each time so it moves to the next element after printing
                inc  si
                loop displayLoop
    ;adding a new line at the end
                mov  dl , 10
                mov  ah , 2
                int  21h
    
                ret
displayArr endp
main endp
end main
