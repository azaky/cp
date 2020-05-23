var
  input:string;
  
begin
  readln(input);
  if input='PAS' then
    begin
writeln('var data:array[1..10000] of longint;');
writeln('    n,i,j,temp:longint;');
writeln('begin');
writeln('  readln(n);');
writeln('  for i:=1 to n do readln(data[i]);');
writeln('  for i:=1 to n-1 do');
writeln('    for j:=i+1 to n do');
writeln('      if (data[i]>data[j]) then');
writeln('      begin');
writeln('        temp:=data[i];');
writeln('        data[i]:=data[j];');
writeln('        data[j]:=temp;');
writeln('      end;');
writeln('  for i:=1 to n do writeln(data[i]);');
writeln('end.');
    end
  else
    begin
writeln('int data[10001];');
writeln('int n,i,j,temp;');
writeln('int main(){');
writeln('  scanf("%d",&n);');
writeln('  for (i=1;i<=n;i++) scanf("%d",data[i]);');
writeln('  for (i=1;i<=n-1;i++)');
writeln('    for (j=i+1;j<=n;j++)');
writeln('      if (data[i]>data[j]){');
writeln('        temp=data[i];');
writeln('        data[i]=data[j];');
writeln('        data[j]=temp;');
writeln('      }');
writeln('  for (i=1;i<=n;i++) printf("%d\n",data[i]);');
writeln('  return 0;');
writeln('}');
    end;
end.
