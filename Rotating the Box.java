class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m=box.length;
        int n=box[0].length;
        char[][] rotatedBox=new char[n][m];

        // Rotating the box by 90 degree
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rotatedBox[i][j] = box[m - 1 - j][i];
            }
        }

        // Iterating from bottom to top
        for(int j=0; j<m; j++){//m:Column
            int b=n-1, t=n-1;
            while(b>=t && t>=0){//n:Row
                if(rotatedBox[b][j]=='#'){
                    b--;
                }
                else if(rotatedBox[b][j]=='.' && rotatedBox[t][j]=='#'){
                    rotatedBox[b][j] = rotatedBox[t][j];
                    rotatedBox[t][j]='.';
                    b--;
                }
                else if(rotatedBox[t][j]=='*'){                    
                    b=t-1;
                }
                t--;
            }
        }


        return rotatedBox;
    }
}
