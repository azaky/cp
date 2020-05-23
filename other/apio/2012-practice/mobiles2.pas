uses math;

var
  n,i,c1,c2,nrose,level,nnode,ans,minlevel,maxlevel:longint;
  idx,tree,ctree:array[0..1 shl 20] of longint;
  leaf,rose,crose:array[0..1 shl 20] of boolean;

procedure compare(v,vc:longint);
  begin
    if leaf[v] then exit;
    if (tree[2*v]=ctree[2*vc]) and (tree[2*v+1]=ctree[2*vc+1]) then
      begin
        compare(2*v,2*vc); compare(2*v+1,2*vc+1);
      end
    else if (tree[2*v]=ctree[2*vc+1]) and (tree[2*v+1]=ctree[2*vc]) then
      begin
        inc(ans); compare(2*v,2*vc+1); compare(2*v+1,2*vc);
      end
    else
      begin
        writeln(-1);halt;
      end;
  end;

begin
  readln(n);
  idx[1]:=1; minlevel:=maxlongint; maxlevel:=0;
  for i:=1 to n do
    begin
      readln(c1,c2);
      if c1=c2 then
        begin
          level:=trunc(ln(idx[i])/ln(2))+1;
          minlevel := min(minlevel,level); maxlevel := max(maxlevel,level);
          leaf[2*idx[i]]:=true; leaf[2*idx[i]+1]:=true;
          continue;
        end;
      if c1<0 then
        begin
          leaf[2*idx[i]]:=true;
          level:=trunc(ln(idx[i])/ln(2))+1;
          minlevel := min(minlevel,level); maxlevel := max(maxlevel,level);
        end
      else
        begin
          idx[c1]:=2*idx[i];
          if idx[c1]>1 shl 18 then
            begin
              writeln(-1);halt;
            end;
        end;
      if c2<0 then
        begin
          leaf[2*idx[i]+1]:=true;
          level:=trunc(ln(idx[i])/ln(2))+1;
          minlevel := min(minlevel,level); maxlevel := max(maxlevel,level);
        end
      else
        begin
          idx[c2]:=2*idx[i]+1;
          if idx[c2]>1 shl 18 then
            begin
              writeln(-1);halt;
            end;
        end;
    end;
  //check if the difference of the levels is at most 1
  if maxlevel=minlevel then
    begin
      writeln(0);halt;
    end
  else if maxlevel-minlevel>1 then
    begin
      writeln(-1);halt;
    end;
  level:=minlevel;
  nnode := (1 shl (level+1))-1;
  //creating roses
  for i:=(nnode+1) div 2 to nnode do
    if not leaf[i] then
      begin
        leaf[i]:=true; leaf[2*i]:=false; leaf[2*i+1]:=false;
        rose[i]:=true; inc(nrose);
      end;
  //creating copy of the tree, which meets brother's requirement
  //the first nrose leaf of the tree must be rose, so
  for i:=(nnode+1) div 2 to ((nnode+1) div 2)+nrose-1 do crose[i]:= true;
  //build the tree as well as the copy of the tree
  for i:=nnode downto 1 do
    if leaf[i] then
      if rose[i] then tree[i]:=1 else tree[i]:=0
    else tree[i]:=tree[2*i]+tree[2*i+1];
  for i:=nnode downto 1 do
    if leaf[i] then
      if crose[i] then ctree[i]:=1 else ctree[i]:=0
    else ctree[i]:=ctree[2*i]+ctree[2*i+1];
  //now, back to the problem
  //compare tree to ctree
  ans:=0; compare(1,1); writeln(ans);
end.
