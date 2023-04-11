<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
 include $this->CompilerInclude("header.htm");
 ?>
    <div id="group_main">
    	<div id="group_main_middle">
        	<div class="group_main_title"><?php echo $lang['group_store_list'];?>
            </div>
        	<div class="group_list_text">
                    <div class="group_list_title">
                    <a href="directry.php"><?php echo $lang['group_store_all'];?></a>--<a href="store.php?id=<?php echo $topid;?>"><?php echo $topstore;?></a><?php if(!empty($store)){?>--<a href="store.php?id=<?php echo $nextid;?>"><?php echo $store;?></a> <?php }?><span>( <?php echo $lang['group_store_now']; echo $a;?>-<?php echo ($a+19); echo $lang['group_store_one'];?>/<?php echo $lang['group_store_count']; echo $n; echo $lang['group_store_one']; echo $lang['group_main_bar'];?> )</span>
                </div>
                <div class="clear">
                </div>
        	</div>
        	<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{

              $row = $fields;
              $icon = $row['groupimg'];
  			  if(!$icon) $icon = "/group/images/group_mainlist00.gif";
            ?>
            <div class="group_list_class">
            	<div class="group_list_class_img"><img src="<?php echo $icon;?>" width="100" />                </div>
                <div class="group_list_class_text">
                	<ul>
                    <li><a href="group.php?id=<?php echo $row['groupid'];?>"><?php echo $row['groupname'];?></a></li>
                    <li><?php echo $lang['group_member_creaters']; echo $row['creater'];?></li>
                    <li><span><?php echo $row['des'];?></span></li>
                    </ul>
                </div>
                <div class="clear">
                </div>
            </div>
            <?php
}
}?>
            <div class="group_more">
            <?php
$atts = array();
$atts['tagname'] = 'pagelist';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

            </div>
        </div>
    </div>
    <div class="clear">
    </div>
<?php include $this->CompilerInclude("footer.htm");
 ?>