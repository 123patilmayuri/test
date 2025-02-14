How Naming Is Managed in CI/CD
Branch	Version Generated	Stored As
feature/foo	1.0.1234-SNAPSHOT	my-app-1.0.1234-SNAPSHOT.jar
main (release)	1.0.1234	my-app-1.0.1234.jar
tag v1.0.0	1.0.0	my-app-1.0.0.jar



✅ Single Build Across Stages (no re-compilation).
✅ Consistent Versioning using GitLab pipeline ID.
✅ Promotion Without Rebuilding (SNAPSHOT to RELEASE).
✅ Deploy the Published Artifact, ensuring production consistency.

 Key Benefits
✅ No double builds – the same artifact is promoted.
✅ No unnecessary rebuilds on main – avoids mismatches.
✅ Ensures traceability – all builds are tracked by CI_PIPELINE_ID.
✅ Repository-driven promotion – handled via Nexus/Artifactory API.



Lambda ---
Recommended Approach
There are two main approaches depending on whether you want manual coordination or a fully automated workflow.

🔹 Option 1: Independent Deployment (Recommended)
✅ Infrastructure & application code can be deployed independently.
✅ Application updates do not require an Infra pipeline run.
✅ More control over versioning & rollback.

🔹 Option 2: Automated Deployment Trigger
✅ Infra pipeline triggers the latest application build.
✅ Ensures infra changes always deploy the latest application.


 aws servicecatalog search-products --query "ProductViewSummaries[?Name=='<PRODUCT_NAME>'].ProductId" --output text
aws servicecatalog describe-product --id <PRODUCT_ID>

 grep "version:" metadata.yaml | awk '{print $2}'
 awk -F': ' '/^version:/ {print $2}' metadata.yaml
grep "version:" metadata.yaml | cut -d':' -f2 | tr -d ' '
