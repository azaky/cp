{
ID: a_zaky01
PROG: picture
LANG: PASCAL
}

type
  rectangle = record
    llx,lly,urx,ury:longint;
  end;
  
var
  n,i,ans:longint;
  rec:array[1..5001] of rectangle;

procedure calh(ax,ay,bx,by,p:longint);
  begin
    while (p=i) or (rec[p].urx<=ax) or (rec[p].llx>=bx) or (rec[p].ury<ay) or (rec[p].lly>ay) do inc(p);
    if p>n then
      begin
        ans:=ans+bx-ax;
        exit;
      end;
    with rec[p] do
      begin
        if ax<llx then calh(ax,ay,llx,by,p+1);
        if bx>urx then calh(urx,ay,bx,by,p+1);
      end;
  end;

procedure calv(ax,ay,bx,by,p:longint);
  begin
    while (p=i) or (rec[p].ury<=ay) or (rec[p].lly>=by) or (rec[p].urx<ax) or (rec[p].llx>ax) do inc(p);
    if p>n then
      begin
        ans:=ans+by-ay;
        exit;
      end;
    with rec[p] do
      begin
        if ay<lly then calv(ax,ay,bx,lly,p+1);
        if by>ury then calv(ax,ury,bx,by,p+1);
      end;
  end;

begin
  {
  assign(input,'picture.in'); reset(input);
  assign(output,'picture.out'); rewrite(output);
  }
  readln(n);
  for i:=1 to n do
    with rec[i] do readln(llx,lly,urx,ury);
  with rec[n+1] do
    begin
      llx:=-1000000;
      lly:=-1000000;
      urx:=1000000;
      ury:=1000000;
    end;
  ans:=0;
  for i:=1 to n do
    with rec[i] do
      begin
        calh(llx,lly,urx,lly,1);
        calh(llx,ury,urx,ury,1);
        calv(llx,lly,llx,ury,1);
        calv(urx,lly,urx,ury,1);
      end;
  writeln(ans);
  {
  close(input);
  close(output);
  }
end.

