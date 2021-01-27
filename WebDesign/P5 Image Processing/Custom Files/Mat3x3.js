class Mat3x3 {
     constructor(a = 1, b = 0, c = 0, d = 0, e = 1, f = 0, g = 0, h = 0, i = 1) {
          this.mat = [
               [a, b, c],
               [d, e, f],
               [g, h, i]
          ];
     }

     multiply(other) {
          if (other instanceof Mat3x3) {
               //Mat * Mat
               let ans = new Mat3x3();
               for (let i = 0; i < 3; i++) {
                    for (let j = 0; j < 3; j++) {
                         let sum = 0;
                         for (let k = 0; k < 3; k++)
                              sum += this.mat[i][k] * other.mat[k][j];
                         ans.mat[i][j] = sum;
                    }
               }
               return ans;
          }
          else if (Array.isArray(other) && other.length == 3) {
               //Mat * vec
               let ans = [0, 0, 0];
               for (let i = 0; i < 3; i++) {
                    for (let j = 0; j < 3; j++) {
                         ans[i] += this.mat[i][j] * other[j];
                    }
               }
               return ans;
          }
          return null;
     }

     scale(factor = 1)
     {
          if(!Number.isFinite(factor)) return;
          for (let i = 0; i < 3; i++) {
               for (let j = 0; j < 3; j++) {
                    this.mat[i][j] *= factor;
               }
          }
     }

     set(i, j, val) {
          if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
          this.mat[i][j] = val;
     }

     get(i, j) {
          if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
          return this.mat[i][j];
     }

     inverse()
     {
          //https://semath.info/src/inverse-cofactor-ex3.html

          //calculate determinant
          let det = this.mat[0][0]*this.mat[1][1]*this.mat[2][2] //11*22*33
               + this.mat[0][1]*this.mat[1][2]*this.mat[2][0]    //12*23*31
               + this.mat[0][2]*this.mat[1][0]*this.mat[2][1]    //13*21*32
               - this.mat[0][2]*this.mat[1][1]*this.mat[2][0]    //13*22*31
               - this.mat[0][1]*this.mat[1][0]*this.mat[2][2]    //12*21*33
               - this.mat[0][0]*this.mat[1][2]*this.mat[2][1];   //11*23*32
          det = 1.0/det;

          //calculate adj(M)
          let adj = new Mat3x3();
          adj.mat[0][0] = this.mat[1][1]*this.mat[2][2] - this.mat[1][2]*this.mat[2][1];
          adj.mat[0][1] = this.mat[0][2]*this.mat[2][1] - this.mat[0][1]*this.mat[2][2];
          adj.mat[0][2] = this.mat[0][1]*this.mat[1][2] - this.mat[0][2]*this.mat[1][1];

          adj.mat[1][0] = this.mat[1][2]*this.mat[2][0] - this.mat[1][0]*this.mat[2][2];
          adj.mat[1][1] = this.mat[0][0]*this.mat[2][2] - this.mat[0][2]*this.mat[2][0];
          adj.mat[1][2] = this.mat[0][2]*this.mat[1][0] - this.mat[0][0]*this.mat[1][2];

          adj.mat[2][0] = this.mat[1][0]*this.mat[2][1] - this.mat[1][1]*this.mat[2][0];
          adj.mat[2][1] = this.mat[0][1]*this.mat[2][0] - this.mat[0][0]*this.mat[2][1];
          adj.mat[2][2] = this.mat[0][0]*this.mat[1][1] - this.mat[0][1]*this.mat[1][0];

          adj.scale(det);
          return adj;
     }
}