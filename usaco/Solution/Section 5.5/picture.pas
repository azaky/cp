{
ID: a_zaky01
PROG: picture
LANG: PASCAL
}

uses math;

Const
    maxn = 10001;

type
    segment = record
      l,r,pos,t:longint;
    end;
    segtree = record
      l,r,val,t:longint;
    end;
    arr = array[0..maxn] of segment;

var
  n,i,llx,lly,urx,ury,maxnode,ans,maxsize,minsize,cur,last:longint;
  row,col:arr;
  tree:array[0..200000] of segtree;

procedure qsort(var a:arr);
  function less(aa,bb:segment):boolean;
    begin
      if aa.pos<bb.pos then exit(true)
        else if aa.pos>bb.pos then exit(false)
          else exit(aa.t>bb.t);
    end;
    
  procedure sort(l,r:longint);
    var
      i,j:longint;
      mid,temp:segment;
    
    begin
      i:=l; j:=r; mid:=a[(l+r) div 2];
      repeat
        while less(a[i],mid) do inc(i);
        while less(mid,a[j]) do dec(j);
        if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
        inc(i); dec(j);
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;
    
  begin
    sort(1,2*n);
  end;

procedure preprocess(node,ll,rr:longint);
  var
    mid:longint;
  
  begin
    maxnode:=max(maxnode,node);
    with tree[node] do
      begin
        l:=ll; r:=rr;
      end;
    if ll=rr then exit;
    if rr-ll=1 then mid:=ll else mid:=(ll+rr) div 2;
    preprocess(2*node,ll,mid); preprocess(2*node+1,mid+1,rr);
  end;

procedure update(node:longint; const ll,rr,tt:longint);
  begin
    if (tree[node].l>rr) or (tree[node].r<ll) then exit;
    if (tree[node].l>=ll) and (tree[node].r<=rr) then
      with tree[node] do
        begin
          t:=t+tt;
          if t>0 then val:=r-l+1 else val:=tree[2*node].val+tree[2*node+1].val;
          exit;
        end;
    update(2*node,ll,rr,tt); update(2*node+1,ll,rr,tt);
    with tree[node] do
      if t>0 then val:=r-l+1
        else val:=tree[2*node].val+tree[2*node+1].val;
  end;

Begin
    Assign(input, 'picture.in'); Reset(input);
    Assign(output, 'picture.out'); Rewrite(output);
	readln(n); minsize:=10001; maxsize:=-10001;
	for i:=1 to n do
	  begin
	    readln(llx,lly,urx,ury);
	    with col[2*i-1] do
	      begin
	        l:=lly; r:=ury; pos:=llx; t:=1;
	      end;
	    col[2*i]:=col[2*i-1]; col[2*i].pos:=urx; col[2*i].t:=-1;
	    with row[2*i-1] do
	      begin
	        l:=llx; r:=urx; pos:=lly; t:=1;
	      end;
	    row[2*i]:=row[2*i-1]; row[2*i].pos:=ury; row[2*i].t:=-1;
        minsize:=min(minsize,min(llx,lly)); maxsize:=max(maxsize,max(urx,ury));
	  end;
	qsort(row); qsort(col);
    ans:=0; maxnode:=0;
	preprocess(1,minsize,maxsize);
	//calculate answer for col
    for i:=1 to maxnode do
      with tree[i] do
        begin
          t:=0; val:=0;
        end;
    last:=0;
    for i:=1 to 2*n do
      begin
        with col[i] do update(1,l+1,r,t);
        cur:=tree[1].val;
        ans:=ans+max(0,cur-last);
        last:=cur;
      end;
    //calculate answer for row
    for i:=1 to maxnode do
      with tree[i] do
        begin
          t:=0; val:=0;
        end;
    last:=0;
    for i:=1 to 2*n do
      begin
        with row[i] do update(1,l+1,r,t);
        cur:=tree[1].val;
        ans:=ans+max(0,cur-last);
        last:=cur;
      end;
    writeln(ans*2);
    Close(input); Close(output);
End.
