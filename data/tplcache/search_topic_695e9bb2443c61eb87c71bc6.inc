<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
 include $this->CompilerInclude("header.htm");
 ?>
    <div id="group_main">
    	<div id="group_main_middle">
        	<div class="group_main_title"><?php echo $lang['group_search']; echo $lang['group_topic_topic'];?>
            </div>
        	<div class="group_list_text">
                    <div class="group_list_title"><?php echo $lang['group_search']; echo $lang['group_search_keywords']; echo $keyword;?></div>
                <div class="clear">
                </div>
        	</div>
            <div class="clear"></div>
			<div class="group_class_forum_text" style="width:758px;margin-left:0px;padding:0px;">
            <div style="height:26px;line-height:26px;">
            <span style="margin-left:21px;float:left;width:280px;"><?php echo $lang['group_topic_titles'];?></span><span style="margin-left:6px;float:left;width:80px;"><?php echo $lang['group_topic_lastpost'];?></span><span style="margin-left:6px;float:left;width:120px;"><?php echo $lang['group_topic_updatetime'];?></span>
            </div>
            <ul>
            <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{

		$rs = $fields;
                	$title = $rs['subject'];
                	if($rs['digest']) $titleleft .= " [<font color=\"red\">".$lang['group_main_digest']."</font>]";
                	if($rs['replies']>10) $titleleft .= "<img src=\"images/icon_hotp.gif\" />";
                    $title = $titleleft.cn_substr($title,40);
                    if(!empty($keyword)) $title = str_replace("$keyword","<font color='red'>$keyword</font>",$title);
                    $titleleft = "";

                ?>
            	<li style="margin-left:8px;width:750px;height:26px;line-height:26px;"><span style="margin-left:0px;float:left;width:280px;"><a href="viewthread.php?id=<?php echo $rs['gid'];?>&tid=<?php echo $rs['tid'];?>" style="color:#000;"><?php echo $title;?></a></span><span style="margin-left:6px;float:left;width:80px;color:#000;"><?php echo $rs['lastposter'];?></span><span style="margin-left:6px;float:left;width:120px;color:#000;"><?php echo date('y-m-d H:i:s',$rs['lastpost']);?></span>
                </li>
                <div class="clear"></div>
<?php
}
}?>
                </ul>
            </div>
            <div class="group_more"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listitem'] = 'info,index,end,pre,next,pageno';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div>
        </div>
    </div>
    <div class="clear">
    </div>
<?php include $this->CompilerInclude("footer.htm");
 ?>