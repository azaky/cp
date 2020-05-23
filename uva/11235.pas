uses math;

var
  n,q,i,p,ansl,ansr,ll,rr:longint;
  a,c,cl,cr,id:array[0..111111] of longint;
  RMQ,l,r:array[0..1 shl 18] of longint;

procedure build(v,ll,rr:longint);
  begin
    l[v] := ll; r[v] := rr;
    if ll=rr then
      begin
        RMQ[v] := c[ll];
        exit;
      end;
    build(2*v,ll,(ll+rr) div 2); build(2*v+1,(ll+rr) div 2+1,rr);
    RMQ[v] := max(RMQ[2*v],RMQ[2*v+1]);
  end;

function get(v,ll,rr:longint):longint;
  begin
    if (r[v]<ll) or (rr<l[v]) then exit(0);
    if (ll<=l[v])and(r[v]<=rr) then exit(RMQ[v]);
    exit(max(get(2*v,ll,rr),get(2*v+1,ll,rr)));
  end;

begin
  a[0] := -111111; cr[0] := 0;
  repeat
    read(n); if n=0 then break else read(q);
    for i:=1 to n do read(a[i]);
    p := 0;
    for i:=1 to n do
      begin
        if a[i]>a[i-1] then
          begin
            inc(p); c[p] := 1;
          end
        else c[p] := c[p] + 1;
        id[i] := p;
      end;
    for i:=1 to p do
      begin
        cl[i] := cr[i-1] + 1;
        cr[i] := cl[i] + c[i] - 1;
      end;
    build(1,1,p);
    for i:=1 to q do
      begin
        read(ll,rr);
        if id[ll] = id[rr] then
          begin
            writeln(rr-ll+1); continue;
          end;
        ansl := cr[id[ll]]-ll+1; ll := id[ll] + 1;
        ansr := rr-cl[id[rr]]+1; rr := id[rr] - 1;
        if ll>rr then
          begin
            writeln(max(ansl,ansr)); continue;
          end;
        writeln(max(max(ansl,ansr),get(1,ll,rr)));
      end;
  until false;
end.
