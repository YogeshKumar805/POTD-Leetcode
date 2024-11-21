class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int cnt=m*n;
        int[][] arr=new int[m][n];

        //Guard value=2;
        for(int i=0; i<guards.length; i++){
            arr[guards[i][0]][guards[i][1]]=2; 
            cnt--; 
        }
        //Wall value=3
        for(int i=0; i<walls.length; i++){
            arr[walls[i][0]][walls[i][1]]=3;
            cnt--; 
        }


        //Traversing the matrix array
        for(int i=0; i<guards.length; i++){
            int r=guards[i][0], c=guards[i][1];
            
            //r: Row fixed
            ////////////////////////////////////////////
            //LEFT::
            for(int j=c-1; j>=0; j--){ //n: Column wise move                               
                if(arr[r][j]==2 || arr[r][j]==3){
                    break;
                }            
                if(arr[r][j]==0)cnt--;     
                arr[r][j]=1;                                
            } 
            //RIGHT::     
            for(int j=c+1; j<n; j++){ //n: Column wise move
                if(arr[r][j]==2 || arr[r][j]==3){
                    break;
                } 
                if(arr[r][j]==0)cnt--;               
                arr[r][j]=1;                                  
            }      

            //c: Column fixed
            ////////////////////////////////////////////
            //UP::
            for(int j=r-1; j>=0; j--){ //m: Row wise move
                if(arr[j][c]==2 || arr[j][c]==3){
                    break;
                }            
                if(arr[j][c]==0)cnt--;    
                arr[j][c]=1;                                 
            }  
            //DOWN::
            for(int j=r+1; j<m; j++){ //m: Row wise move                
                if(arr[j][c]==2 || arr[j][c]==3){
                    break;
                }                                                
                if(arr[j][c]==0) cnt--;                  
                arr[j][c]=1;                
            }     

        }


        return cnt;
    }
}
