n=int(input("N for NxN"))
board=[[0 for i in range(n)]for j in range(n)]
def display(board):#n=len(board)
    for i in range(n):
        print(board[i])
display(board)     
def safe(board,row,column):
    for k in range(n):
        if(board[k][column]==1):
            return False
    for k in range(1,n):
        if all(0<=x<n for x in [row-k,column-k]):
            if(board[row-k][column-k]==1):
                return False
        if all(0<=x<n for x in [row-k,column+k]):
            if(board[row-k][column+k]==1):
                return False
    return True
def nqueen(board,row):
    if(row==n):
        display(board)
        print("\n")
        return
    for col in range(n):
        if safe(board,row,col):
            board[row][col]=1
            nqueen(board,row+1)
            board[row][col]=0
nqueen(board,0)            
    
        
            
