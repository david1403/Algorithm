import java.io.*;
import java.util.*;

class p {
    int x, y, z;
    p(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

}

public class Q16895{
    public static int board[][][][] = new int [5][4][5][5];
    //public static int temp[][] = new int[5][5];
    public static int arr[] = new int[5];
    public static int arr2[] = new int[5];

    public static int v[] = new int[5];
    public static int cube[][][] = new int [5][5][5];

    public static int[] dx = {-1, 0, 0, 1, 0, 0};
    public static int[] dy = {0, -1, 1, 0, 0, 0};
    public static int[] dz = {0, 0, 0, 0, -1 , 1};

    public static int visited[][][] = new int[5][5][5];
    public static int answer = 987654321;


    public static void turn(int index) {
        if (index == 5) {
            //System.out.println(Arrays.toString(arr2));
            //System.out.println(Arrays.toString(arr));
            for (int i = 0 ; i < 5 ; i++) {
                for (int j = 0 ; j < 5 ; j++) {
                    for (int k = 0 ; k < 5 ; k++) {
                        cube[i][j][k] = board[arr[i]][arr2[i]][j][k];
                        visited[i][j][k] = -1;
                    }
                }
            }
            if (cube[0][0][0] == 0 || cube[4][4][4] == 0) {
                return;
            }
            Queue <p> q = new LinkedList<p> ();
            p start = new p(0, 0, 0);
            visited[0][0][0] = 0;
            q.offer(start);
            while(!q.isEmpty()) {
                int cx = q.peek().x;
                int cy = q.peek().y;
                int cz = q.peek().z;
                q.poll();
                for (int i = 0 ; i < 6 ; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    int nz = cz + dz[i];
                    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && 0 <= nz && nz < 5) {
                        if (visited[nx][ny][nz] == -1 && cube[nx][ny][nz] == 1) {
                            visited[nx][ny][nz] = visited[cx][cy][cz] + 1;
                            q.offer(new p(nx, ny, nz));
                        }
                    }
                }
            }
            if (visited[4][4][4] != -1 && visited[4][4][4] < answer) {
                answer = visited[4][4][4];
            }
            
            return;
        }
        for (int i = 0 ; i < 4 ; i++) {
            arr2[index] = i;
            turn(index + 1);
        }
    }

    public static void solve(int index) {
        if (index == 5) {
            turn(0);
            


            return;
        }
        for (int i = 0 ; i <= 4 ; i++) {
            if (v[i] == 0) {
                v[i] = 1;
                arr[index] = i;
                solve(index + 1);
                v[i] = 0;
            }
        }
    }




    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0 ; i < 25 ; i++) {
            String[] s = br.readLine().split(" ");
            for (int j = 0 ; j < 5 ; j++) {
                board[i/5][0][i%5][j] = Integer.parseInt(s[j]);
            }
        }
        for (int i = 0 ; i < 5 ; i++) {
            for (int j = 1 ; j < 4 ; j++) { 
                for (int k = 0 ; k < 5 ; k++) {
                    for (int l = 0 ; l < 5 ; l++) {
                        board[i][j][l][4-k] = board[i][j-1][k][l];
                    }
                }
            }
        }  
        solve(0);
        System.out.println(answer == 987654321 ? -1 : answer);
    }
}