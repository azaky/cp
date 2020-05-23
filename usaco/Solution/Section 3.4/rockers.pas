{
ID: a_zaky01
PROG: rockers
LANG: PASCAL
}

var
  n,m,t,i,ans:integer;
  used:array[1..21] of boolean;
  size,len:array[1..20] of longint;
  fin,fout:text;

procedure search(k:integer);
  var
    disk,i,total:integer;

  begin
    if k>n then
      begin
        fillchar(size,sizeof(size),0);
        disk:=1;
        i:=1;
        total:=0;
        while true do
          begin
            while not used[i] and (i<=n) do inc(i);
            if i>n then break;
            if size[disk]+len[i]<=t then
              begin
                inc(total);
                inc(size[disk],len[i]);
                inc(i);
              end
            else if disk<m then inc(disk)
              else break;
          end;
        if total>ans then ans:=total;
      end
    else
      begin
        used[k]:=false;
        search(k+1);
        used[k]:=true;
        search(k+1);
      end;
  end;

begin
  assign(fin,'rockers.in');
  assign(fout,'rockers.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,t,m);
  for i:=1 to n do read(fin,len[i]);
  search(1);
  writeln(fout,ans);
  close(fin);
  close(fout);
end.
