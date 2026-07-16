class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rc = len(matrix)
        cc= len(matrix[0])
        rows= [False]*rc
        cols= [False]*cc
        is_empty= True

        for i in range(rc):
            for j in range(cc):
                if matrix[i][j]==0:
                    rows[i]=True
                    cols[j]=True
                    is_empty= False
        if not is_empty:
            for i in range(rc):
                for j in range(cc):
                    if rows[i] or cols[j]:
                        matrix[i][j]=0            
       
    


