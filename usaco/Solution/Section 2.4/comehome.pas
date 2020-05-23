{
ID: a_zaky01
PROG: comehome
LANG: PASCAL
}

const
  abjad='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz';

var
  n,i,d,pas:integer;
  ans:longint;
  input1,input2,space:char;
  stat:array[1..52] of boolean;
  len:array[1..52,1..52] of integer;
  dis:array[1..52] of longint;
  fin,fout:text;

procedure dijkstra(p,k:longint);
  var
    i:integer;

  begin
    if (p=26) or ((p<>26) and ((dis[p]=0) or (dis[p]>k))) then
      begin
        dis[p]:=k;
        for i:=1 to 52 do
          if (stat[i]) and (len[p,i]>0) and (p<>i) then dijkstra(i,k+len[p,i]);
      end;
  end;

begin
  assign(fin,'comehome.in');
  assign(fout,'comehome.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      read(fin,input1,space,input2);
      readln(fin,d);
      stat[pos(input1,abjad)]:=true;
      stat[pos(input2,abjad)]:=true;
      if (len[pos(input1,abjad),pos(input2,abjad)]=0) or (len[pos(input1,abjad),pos(input2,abjad)]>d) then
        begin
          len[pos(input1,abjad),pos(input2,abjad)]:=d;
          len[pos(input2,abjad),pos(input1,abjad)]:=d;
        end;
    end;
  dijkstra(26,0);
  ans:=0;
  for i:=1 to 25 do
    if stat[i] then
      if (ans=0) or (ans>dis[i]) then
        begin
          pas:=i;
          ans:=dis[i];
        end;
  writeln(fout,abjad[pas],' ',ans);
  close(fin);
  close(fout);
end.
