const sigma = (a, b, f) => {
  sum = 0;
  for (let i = a; i <= b; i++) sum += f(i);
  return sum;
};

// const t = [0, 0, 2, 1, 1, 2];
// const a = [0, 1, 2, 1, 1];
// const k = 4;

// const ans = sigma(1, k, i => (a[i] + t[i+1]) * sigma(1, i-1, j => (i - j) * (t[j] + a[j])));

// for (let i = 4; i >= 1; i--) {
//   const c = sigma(1, i-1, j => (i - j) * (t[j] + a[j]));
//   console.log(`(${(a[i] + t[i+1])}) * ${c}`);
//   for (let j = 1; j < i; j++) {
//     console.log(`\t${i-j} * ${t[j]+a[j]}`);
//   }
// }

// console.log(ans);

const t = [0, 0, 1, 1];
const a = [0, 1, 1];
const k = 2;

const ans = 2 + t[1] * 


sigma(1, k, i => (a[i] + t[i+1]) * sigma(1, i-1, j => (i - j) * (t[j] + a[j]))) +
  sigma(1, k, i => (a[i] + t[i+1]) * (
    sigma(1, k, j => (k + i - j) * (t[j] + a[j])) +
      t[k+1] * (i-1) +
      sigma(1, i-1, j => (i-j) * (t[j] + a[j]))));

console.log(ans);

const F = sigma(1, k-1, j => (k - j) * (t[j] + a[j]));
const S = sigma(1, k, j => j * (t[j] + a[j]));
console.log('F', F);
console.log('S', S);

const X = sigma(1, k, i => (t[i+1] + a[i]) * (i-1));
